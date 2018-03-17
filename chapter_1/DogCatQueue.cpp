#include <iostream>
#include <cassert>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

class Pet
{
public:
	Pet(string type) :_type(type){}
	string getType()
	{
		return _type;
	}
private:
	string _type;
};

class Dog : public Pet
{
public:
	Dog() : Pet("Dog"){}
};

class Cat : public Pet
{
public:
	Cat() : Pet("Cat"){}
};

class PetEnterQueue
{
public:
	PetEnterQueue(Pet pet, long count) : _pet(pet), _count(count)
	{}

	Pet getPet()
	{
		return _pet;
	}

	long getCount()
	{
		return _count;
	}

	string getEnterPetType()
	{
		return _pet.getType();
	}

private:
		Pet _pet;
		long _count;
		 
};

class DogCatQueue
{
public:
	DogCatQueue() : _count(0){}
	
	void add(Pet pet)
	{
		if (pet.getType() == "Dog")
		{
			dogQ.push(PetEnterQueue(pet, this->_count++));
		}
		else if (pet.getType() == "Cat")
		{
			catQ.push(PetEnterQueue(pet, this->_count++));
		}
		else
		{
			return;
		}
	}

	Pet popDog()
	{
		assert(!this->dogQ.empty());
		Pet dog = this->dogQ.front().getPet();
		dogQ.pop();

		return dog;
	}

	Pet popCat()
	{
		assert(!this->catQ.empty());
		Pet cat = this->catQ.front().getPet();
		dogQ.pop();

		return cat;
	}

	Pet popAny()
	{
		assert(!this->dogQ.empty() && !this->catQ.empty());

		if (!this->dogQ.empty() && !this->catQ.empty())
		{
			if (this->dogQ.front().getCount() < this->catQ.front().getCount())
			{
				return popDog();
			}
			else
				return popCat();
		}
		else if (!this->dogQ.empty())
		{
			return popDog();
		}
		else
		{
			return popCat();
		}
	}

	bool isEmpty()
	{
		return this->dogQ.empty() && this->catQ.empty();
	}

	bool isDogQueueEmpty()
	{
		return this->dogQ.empty();
	}

	bool isCatQueueEmpty()
	{
		return this->catQ.empty();
	}

private:
	queue<PetEnterQueue> dogQ;
	queue<PetEnterQueue> catQ;
	long _count;
};

int main(void)
{
	DogCatQueue q;

	q.add(Dog());
	q.add(Dog());
	q.add(Dog());
	q.add(Cat());
	q.add(Cat());

	cout << q.popAny().getType() << endl;
	cout << q.popCat().getType() << endl;
	cout << q.popDog().getType() << endl;
	
	return 0;
}

