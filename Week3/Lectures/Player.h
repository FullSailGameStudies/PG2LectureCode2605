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

