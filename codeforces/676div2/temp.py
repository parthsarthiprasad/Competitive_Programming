import pandas as pd
import numpy as np

import glob
import os

from datetime import datetime

import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.callbacks import ModelCheckpoint
from sklearn.model_selection import train_test_split

# Cufflinks wrapper on plotly
import cufflinks
from IPython.core.interactiveshell import InteractiveShell
InteractiveShell.ast_node_interactivity = 'all'

from plotly.offline import iplot
cufflinks.go_offline()

# Set global theme

import plotly.figure_factory as ff

import plotly.graph_objects as go




def performance_summary(model, X_test, y_test ):
    
    y_hat=model.predict(X_test)
    
    df_summary=pd.DataFrame(y_hat, columns=["y_hat"])
    df_summary["y_true"]=y_test
    df_summary["abs_error"]=np.abs(df_summary.y_true-df_summary.y_hat)
    df_summary["error"]=df_summary.y_hat-df_summary.y_true
    df_summary["relative_error"]= df_summary["error"]/df_summary.y_true
    df_summary["relative_abs_error"]= df_summary["abs_error"]/df_summary.y_true
    
    share_within_5pct=(df_summary.query("relative_abs_error<0.05").shape[0]/df_summary.shape[0])*100
    
    print("{:.2f}% : Share of forecasts within 5% absolute error\n".format(share_within_5pct))
    print("{:.0f}   : Mean absolute error \n".format(df_summary.abs_error.mean()))
    print("{:.2f}% : Mean absolute percentage error\n".format(df_summary.relative_abs_error.mean()*100))


def DNN_plot_loss(history, starting_epoch,previous_val_loss):

        trace0=go.Scatter(
                y=history.history['loss'][starting_epoch:],
                x=history.epoch[starting_epoch:],
                mode='lines',
                marker=dict(
                color="blue",
                size=5,
                opacity=0.5
                ),
                name="Training Loss"
            )


        trace1=go.Scatter(
                y=history.history['val_loss'][starting_epoch:],
                x=history.epoch[starting_epoch:],
                mode='lines',
                marker=dict(
                color="red",
                size=5,
                opacity=0.5
                ),
                name="Validation Loss"
            )
        
        trace2=go.Scatter(
                y=list(np.ones([len(history.epoch[starting_epoch:])])*np.asarray(previous_val_loss).min()),
                x=history.epoch[starting_epoch:],
                mode='lines',
                marker=dict(
                color="grey",
                size=5,

                ),
                name="Lowest error from previous models"
            )

        data=[trace0, trace1,trace2]
        figure=go.Figure(
            data=data,
            layout=go.Layout(
                title="Learning curve",
                yaxis=dict(title="Loss",range=(900,1500)),
                xaxis=dict(title="Epoch",range=(starting_epoch,history.epoch[-1])),
                legend=dict(
                    x=0.57,
                    y=1,
                    traceorder="normal",
                    font=dict(
                        family="sans-serif",
                        size=12,
                        color="black"
                    ),
                bgcolor=None,



            )))
        iplot(figure)




df = pd.read_csv(r"https://raw.githubusercontent.com/Jan-Majewski/Project_Portfolio/master/03_Real_Estate_pricing_in_Warsaw/top_features_data.csv")
print("Data dimensions: {}".format(df.shape))



## Extracting X and y from data, removing features not used in regression
y=df.unit_price
X=df.drop(columns=["unit_price","lat_mod","lon_mod"])


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=15)
df.columns



# Reshaping y
y_train=np.asarray(y_train).reshape(-1,1)
y_test=np.asarray(y_test).reshape(-1,1)

#Standarizing X
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_train=scaler.fit_transform(X_train)
X_test=scaler.transform(X_test)

tf.keras.backend.clear_session()
tf.random.set_seed(60)

model=keras.models.Sequential([
    
    keras.layers.Dense(512, input_dim = X_train.shape[1], activation='relu'),  
    keras.layers.Dense(512, input_dim = X_train.shape[1], activation='relu'),  
    keras.layers.Dense(units=256,activation='relu'),  
    keras.layers.Dense(units=256,activation='relu'),    
    keras.layers.Dense(units=128,activation='relu'),
    keras.layers.Dense(units=1, activation="linear"),



],name="Initial_model",)

model.summary()

optimizer = keras.optimizers.Adam()



model.compile(optimizer=optimizer,  
            loss='mean_absolute_error')


history = model.fit(X_train, y_train,
                    epochs=200, batch_size=1024,
                    validation_data=(X_test, y_test), 
                    verbose=1)


DNN_plot_loss(history,starting_epoch=10, previous_val_loss=[0])
# Storing model performance as reference for tracking progress, evaluating key KPIs
previous_val_loss=[history.history["val_loss"][-1]]
performance_summary(model, X_test, y_test )

tf.keras.backend.clear_session()
tf.random.set_seed(60)

model=keras.models.Sequential([
    
    keras.layers.Dense(512, input_dim = X_train.shape[1], activation='relu'),  
    keras.layers.Dropout(0.3),
    
    keras.layers.Dense(512, activation='relu'),  
    keras.layers.Dropout(0.3),

    keras.layers.Dense(units=256,activation='relu'), 
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=256,activation='relu'), 
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=128,activation='relu'),
    keras.layers.Dense(units=1, activation="linear"),



],name="Dropout",)


model.summary()

optimizer = keras.optimizers.Adam()



model.compile(optimizer=optimizer,  
            loss='mean_absolute_error')


history = model.fit(X_train, y_train,
                    epochs=200, batch_size=1024,
                    validation_data=(X_test, y_test), 
                    verbose=1)

DNN_plot_loss(history,starting_epoch=10, previous_val_loss=previous_val_loss)

# Storing model performance as reference for tracking progress, evaluating key KPIs
previous_val_loss.append(history.history["val_loss"][-1])
performance_summary(model, X_test, y_test )

tf.keras.backend.clear_session()
tf.random.set_seed(60)

model=keras.models.Sequential([
    
    keras.layers.Dense(512, input_dim = X_train.shape[1], activation='relu'), 
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),
    
    keras.layers.Dense(512, activation='relu'),  
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),

    keras.layers.Dense(units=256,activation='relu'), 
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=256,activation='relu'), 
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=128,activation='relu'),
    keras.layers.Dense(units=1, activation="linear"),



],name="Batchnorm",)

model.summary()

optimizer = keras.optimizers.Adam()



model.compile(optimizer=optimizer,  
            loss='mean_absolute_error')


history = model.fit(X_train, y_train,
                    epochs=200, batch_size=1024,
                    validation_data=(X_test, y_test), 
                    verbose=1)

previous_val_loss[-1]

DNN_plot_loss(history,starting_epoch=10, previous_val_loss=previous_val_loss)
# Storing model performance as reference for tracking progress, evaluating key KPIs
previous_val_loss.append(history.history["val_loss"][-1])
performance_summary(model, X_test, y_test )

tf.keras.backend.clear_session()
tf.random.set_seed(60)

model=keras.models.Sequential([
    
    keras.layers.Dense(512, input_dim = X_train.shape[1]), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),
    
    keras.layers.Dense(512),  
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),

    keras.layers.Dense(units=256), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=256), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=128),
    keras.layers.LeakyReLU(), 
    keras.layers.Dense(units=1, activation="linear"),



],name="LeakyRELU",)

model.summary()

optimizer = keras.optimizers.Adam()



model.compile(optimizer=optimizer,  
            loss='mean_absolute_error')


history = model.fit(X_train, y_train,
                    epochs=300, batch_size=1024,
                    validation_data=(X_test, y_test), 
                    verbose=1)


DNN_plot_loss(history,starting_epoch=10, previous_val_loss=previous_val_loss)
# Storing model performance as reference for tracking progress, evaluating key KPIs
previous_val_loss.append(history.history["val_loss"][-1])
performance_summary(model, X_test, y_test )

tf.keras.backend.clear_session()
tf.random.set_seed(60)

model=keras.models.Sequential([
    
    keras.layers.Dense(1024, input_dim = X_train.shape[1]), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.4),
    
    keras.layers.Dense(512),  
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),

    keras.layers.Dense(512),  
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),
    
    keras.layers.Dense(units=256), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=256), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.01),

    
    keras.layers.Dense(units=128),
    keras.layers.LeakyReLU(), 
    keras.layers.Dropout(0.05),
    keras.layers.Dense(units=1, activation="linear"),



],name="Larger_network",)

model.summary()

optimizer = keras.optimizers.Adam()



model.compile(optimizer=optimizer,  
            loss='mean_absolute_error')


history = model.fit(X_train, y_train,
                    epochs=300, batch_size=1024,
                    validation_data=(X_test, y_test), 
                    verbose=1)

DNN_plot_loss(history,starting_epoch=10, previous_val_loss=previous_val_loss)
# Storing model performance as reference for tracking progress, evaluating key KPIs
previous_val_loss.append(history.history["val_loss"][-1])
performance_summary(model, X_test, y_test )

tf.keras.backend.clear_session()
tf.random.set_seed(60)

model=keras.models.Sequential([
    
    keras.layers.Dense(1024, input_dim = X_train.shape[1]), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.4),
    
    keras.layers.Dense(512),  
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),

    keras.layers.Dense(512),  
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),
    
    keras.layers.Dense(units=256), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.2),
    
    keras.layers.Dense(units=256), 
    keras.layers.LeakyReLU(),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.01),

    
    keras.layers.Dense(units=128),
    keras.layers.LeakyReLU(), 
    keras.layers.Dropout(0.05),
    keras.layers.Dense(units=1, activation="linear"),



],name="Learning_rate_decay",)



# Calculating learning rate decay
learning_rate = 0.005
decay = 5e-4
n_epochs=400
n_steps_per_epoch = len(X_train) // 1024
epochs = np.arange(n_epochs)
lrs = learning_rate / (1 + decay * epochs * n_steps_per_epoch)

# Visualizing learning rate decay

trace0=go.Scatter(
            y=lrs,
            x=epochs,
            mode='lines',
            marker=dict(
            color="red",
            size=5,
            opacity=0.5
            )
    )
        

data=[trace0]
figure=go.Figure(
            data=data,
            layout=go.Layout(
                title="Learning rate decay",
                yaxis=dict(title="Learning rate"),
                xaxis=dict(title="Epoch"),
                legend=dict(
                    x=1,
                    y=1,
                    traceorder="normal",
                    font=dict(
                        family="sans-serif",
                        size=12,
                        color="black"
                    ),
                bgcolor=None


            )))
iplot(figure)

#Added learning rate decay to Adam optimizer
optimizer = keras.optimizers.Adam(lr=0.005, decay=5e-4)



model.compile(optimizer=optimizer,  
            loss='mean_absolute_error')


history = model.fit(X_train, y_train,
                    epochs=400, batch_size=1024,
                    validation_data=(X_test, y_test), 
                    verbose=1)



DNN_plot_loss(history,starting_epoch=10, previous_val_loss=previous_val_loss)
# Storing model performance as reference for tracking progress, evaluating key KPIs
previous_val_loss.append(history.history["val_loss"][-1])
performance_summary(model, X_test, y_test )


# Combining validation loss with model names
models=["basic_model","dropout","batch_norm","leakyRELU","1024_layer","lr_decay"]
df_comparison=pd.DataFrame(previous_val_loss,columns=["val_loss"])
df_comparison["model"]=models



# Plotting model evolution
import plotly.express as px

fig = px.line(df_comparison, x="model", y="val_loss")
fig.show()






