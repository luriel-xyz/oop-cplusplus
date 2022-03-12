/** main.cpp
 *	
 *  The code demonstrates the use of basic Object-Oriented Programming concepts. 
 *  Based on the code, we can see the usage of constructors, mutators, 
 *  accessors, and exception handling.
 *   
 *  @author     Jayden Roberts
 *  @author     Luriel Mapili
 *  @since      5 Feb 2022
*/

#include <iostream>
#include <iomanip> // for output formatting
#include <stdexcept> // for invalid_argument

using namespace std;

// Class declaration section
class Box
{   
    public:	
        // Default constructor
        Box(): height(1.0), width(1.0), depth(1.0) {}
        
        // Parametrized constructor
        Box(double height, double width, double depth);

        // Accessors
        double GetHeight() const { return height; } // gets height as a double
        double GetWidth() const { return width; } // gets width as a double
        double GetDepth() const { return depth; } // gets depth as a double
        double GetVolume() const; // calculates the volume of the box
        string ToString() const; // convert the obj to a string.

        // Mutators
        void SetHeight(double height); // sets the value of the height
        void SetWidth(double width); // sets the value of the width
        void SetDepth(double depth); // sets the value of the depth
        void Resize(double height, double width, double depth); //sets the value
                                                  // of all private data members

        // A constant that defines the minimum value of the box dimensions
        const double MIN_DIMENSION_VALUE = 0.01;
    // Private members
    private:
        // Private data members
        double height; // a double precision number to represent the height
        double width; // a double precision number to represent the width
        double depth; // a double precision number to represent the depth
		
}; // end of class declaration section

// The main function
int main() 
{
    // Output an information header
    cout << "Box Class Demo" << endl
             << "======================" << endl;

    try
    {
        // DECLARATIONS
        // Default constructor
        Box box1Obj;

        // Parametrized constructor
        Box box2Obj(10.5, 12, 13.3);

        // Display the boxes as initialized
        cout << "As Initialized" << endl
                 << "============================" << endl
                 << "box1Obj: \n" << box1Obj.ToString() << endl
                 << "\nbox2Obj: \n" << box2Obj.ToString() << endl << endl;
        
        // Resize the box1Obj
        box1Obj.Resize(96.8, 8.95, 10);
        
        // Display the box information
        cout << "After resizing: " << endl
                << "============================" << endl
                << "box1Obj: \n" << box1Obj.ToString() << endl;
    }
    catch(const exception& ex)
    {
        cerr << ex.what(); // display the exception message.
    }

    cout << endl << endl;
    
    return 0;
}

// Class definition section (method definitions)

/** Parametrized Constructor for Box class
 *  @param	height: double (a number with a minimum value of 0.01)
 *  @param	width: double (a number with a minimum value of 0.01)
 *  @param	depth: double (a number with a minimum value of 0.01)
 *  @throws	invalid_argument exception if any of the dimension attributes 
 *              have a value lesser than the minimum value (0.01)
 */
Box::Box(double height, double width, double depth)
{   
    // Set the height, width and depth
    Resize(height, width, depth);
}

/** SetHeight Method for Box class
 *  Sets the height of this Box object.
 *  @param  height: double
 *  @throws invalid_argument exception if the height is invalid
 */
void Box::SetHeight(double height)
{
    // if the height parameter is invalid
    if(height < MIN_DIMENSION_VALUE)
    {
        // throw an appropriate exception
        throw invalid_argument("The height should have a minimum value of " 
                                + to_string(MIN_DIMENSION_VALUE));
    }
    
    // Set height value to the parameter
    Box::height = height;
}

/** SetWidth Method for Box class
 *  Sets the width of this Box object.
 *  @param  height: double
 *  @throws invalid_argument exception if the width is invalid
 */
void Box::SetWidth(double width)
{
    // if the width parameter is invalid
    if(width < MIN_DIMENSION_VALUE)
    {
        // throw an appropriate exception
        throw invalid_argument("The width should have a minimum value of " 
                                + to_string(MIN_DIMENSION_VALUE));
    }
    
    // Set width value to the parameter
    Box::width = width;
}

/** SetDepth Method for Box class
 *  Sets the depth of this Box object.
 *  @param  depth: double
 *  @throws invalid_argument exception if the width is invalid
 */
void Box::SetDepth(double depth)
{
    // if the depth parameter is invalid
    if(depth < MIN_DIMENSION_VALUE)
    {
        // throw an appropriate exception
        throw invalid_argument("The depth should have a minimum value of " 
                                + to_string(MIN_DIMENSION_VALUE));
    }
    
    // Set depth value to the parameter
    Box::depth = depth;
}

/** Resize Method for Box class
 *  Sets the height, width, and depth of the Box object.
 *  @param  height: double
 *  @param  width: double
 *  @param  depth: double
 *  @throws invalid_argument exception if the height, width, or depth are invalid
 */
void Box::Resize(double height, double width, double depth)
{
    // Set the height, width, and depth values
    SetHeight(height);
    SetWidth(width);
    SetDepth(depth);
}

/** GetVolume Method for Box class
 *  Calculates and returns the volume of the box
 *  @return the calculated volume of the box
 */
double Box::GetVolume() const
{
    return (height * width * depth);
}

/** ToString Method for Box class
 *  Converts the obj to a string.
 *  @return the obj state as a string
 */
string Box::ToString() const
{
    // declare an empty string
    string boxString = "height: " + to_string(Box::height)
                        + "\nwidth: " + to_string(Box::width)
                        + "\ndepth: " + to_string(Box::depth)
                        + "\nvolume: " + to_string(Box::GetVolume());
    
    // return the string
    return boxString;
}