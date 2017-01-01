 -- SJ version
// static method do not exist, but you can create static class
// since there is no '#' it will create an instance not a type
staticA : (
	DoStatic :# () {}
)

A :# (
	DoMethod :# () {}
	DoVirtualMethod :# () {}
)

B :# A(
	// any method can be overriden if the name is the same
	DoVirtualMethod :# () {
		// you can only invoke the base version of this method
		// base acts a variable, so you cannot change the parameters
		// passed to the base class
		base
	}
)

-- C# version
class A
{
	static DoStatic() {}
	void DoMethod() {}
	virtual void DoVirtualMethod() {}	
}

class B : A
{
	override void DoVirtualMethod() {
		base.DoVirtualMethod()
	}		
}