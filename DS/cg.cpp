#include <iostream> 
using namespace std; 
 const int INSIDE = 0; // 0000 
    const int LEFT = 1; // 0001 
    const int RIGHT = 2; // 0010 
    const int BOTTOM = 4; // 0100 
    const int TOP = 8; // 1000 
    int x_max;
    int x_min;
    int y_max;
    int y_min;

int computeCode(double x, double y) 
{  
	int code = INSIDE; 

	if (x < x_min)  
		code |= LEFT; 
	else if (x > x_max) 
		code |= RIGHT; 
	if (y < y_min) 
		code |= BOTTOM; 
	else if (y > y_max) 
		code |= TOP; 
	return code; 
} 

void clipLine(double x1, double y1, 
						double x2, double y2) 
{ 
	int code1 = computeCode(x1, y1); 
	int code2 = computeCode(x2, y2); 

	bool accept = false; 

	while (true) { 
		if ((code1 == 0) && (code2 == 0)) { 
			// Trivial case
            accept = true; 
			break; 
		} 
		else if (code1 & code2) { 
            // Trivial case    
			break; 
		} 
		else { 
            // General / Non Trivial case
			int code_out; 
			double x, y; 

			if (code1 != 0) 
				code_out = code1; 
			else
				code_out = code2; 

			if (code_out & TOP) { 
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); 
				y = y_max; 
			} 
			else if (code_out & BOTTOM) { 
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); 
				y = y_min; 
			}
			else if (code_out & RIGHT) { 
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); 
				x = x_max; 
			} 
			else if (code_out & LEFT) { 
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); 
				x = x_min; 
			} 

			if (code_out == code1) { 
				x1 = x; 
				y1 = y; 
				code1 = computeCode(x1, y1); 
			} 
			else { 
				x2 = x; 
				y2 = y; 
				code2 = computeCode(x2, y2); 
			} 
		} 
	} 
	if (accept) { 
		cout << "Line accepted from " << x1 << ", "
			<< y1 << " to " << x2 << ", " << y2 << endl; 
	} 
	else
		cout << "Line rejected" << endl; 
} 

int main() 
{
   

    cout<<"Enter dimensions of rectangular clipping window";
    cout<<"X Max:   ";
    //int x_max;
    cin>>x_max;  
    cout<<"Y Max:   ";
    //int y_max;
    cin>>y_max; 
    cout<<"X Min:   ";
    //int x_min;
    cin>>x_min; 
    cout<<"Y Min:   ";
    //int y_min;
    cin>>y_min; 
 
    cout<<"Enter the number of lines to be clipped: ";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x1,y1,x2,y2;
        cout<<"Enter x coordinate of 1st point";
        cin>>x1;
        cout<<"Enter y coordinate of 1st point";
        cin>>y1;
        cout<<"Enter x coordinate of 2nd point";
        cin>>x2;
        cout<<"Enter y coordinate of 2nd point";
        cin>>y2;
        clipLine(x1,y1,x2,y2);
    }
	return 0; 
}