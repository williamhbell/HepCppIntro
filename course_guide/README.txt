This is a rather complicated solution.  The example is complicated
because its private data member m_array is a pointer.  When a function
is called with an object rather than a pointer the object within that
function is a copy of the one that was passed to it.  If no copy
constructor is defined the default one is used.  The default copy
constructor simply copies the data members from one class into the
copy.  This becomes a problem when the function using the copy of the
object finishes.  When the function finishes the local copy of the
object is destroyed and the destructor is called.  The destructor
deletes the object the pointer points to and because this pointer has
the same address as the one it was copied from the private data member
in the original is deleted!


fun (Object obj) { // A copy of object obj is created

}  // The copy of object obj is deleted and therefore its destructor
   // is called.


To get around this problem there are two possible solutions : (1)
always use pointers to DataContainer classes, (2) define a copy
constructor.  Picking the sensible option 2, a copy constructor was
defined to copy the values rather than the memory address of the
pointer.  Run the program to see when this is called.
