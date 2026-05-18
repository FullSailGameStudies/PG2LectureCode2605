#pragma once
#include <string>
class Player
{
	//data members (describe the object)
	//member functions (what the object can do)
	
	//Who should see the parts?
	//Access modifiers:
	//public - ALL other code can see it
	//private (default) - ONLY* this class can see it
	//protected - this class and all its descendents can see it

public:
	//constructors (ctors)
	//  purpose: to initialize the fields
	//	the compiler will create a default ctor IF we do not
	//		create one ourselves
	//	IF we create a ctor, the compiler's ctor is NOT created
	//	a default ctor: a ctor w/out parameters
	//  can have as many ctors as you need
	//  they can be public/private/protected
	//	rules for ctors:
	//		1) MUST be named the same as the class
	//		2) cannot have a return type at all (not even void)
	Player() //a default ctor
	{
		name_ = "";
		health_ = 1.0f;
		score_ = 0;
	}

	//use the member initialization list to initialize the fields
	Player(const std::string& name, float health, int score) :
		name_(name),
		health_(health),
		score_(score)
	{
	}

	//getters/setters
	//	gatekeepers of your data
	//  usually public so other code can use them
	//  they can be defined (code) in the header
	// 
	//getters (accessors)
	//	usually const methods (they do not change the object)
	//	the return type matches the field type
	//	usually no parameters
	//  if the return type is a class, use a const &
	const std::string& GetName() const
	{
		return name_;
	}
	//alternate naming convention
	float Health() const { return health_; }

	//setters (mutators)
	//	return type is usually void
	//	has a parameter that matches the field type
	//	cannot be const
	void SetName(const std::string& name)
	{
		//validation logic
		// code that checks the parameter
		//	to make sure it is valid
		if (name.size() > 0 && name.size() < 32)
		{
			name_ = name;//update the field
		}
	}

	void Health(float health)
	{
		if (health >= 0 && health <= 1.0f)
			health_ = health;
	}


	//FIELDS (data members)
	//in general, they should be private
	//naming conventions:
	//   camelCasingNamingConvention
	//   for fields, add something to make it standout
	//		vs other variables
private:
	std::string name_;
	float health_;
	int score_;
};

