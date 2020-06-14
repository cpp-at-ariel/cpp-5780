/**
 * A demo implementation of a unique pointer.
 * 
 * Author: Eran Kaufmann
 * Since:  2020-06
 */

template<typename T> class UniquePointer {
	T* ptr = nullptr;

public:
	UniquePointer()=default;

	// Convert from C pointer:
	UniquePointer(T* t): ptr(t) {} 

	// Behave like C pointer:
	T* operator->(){
		return ptr;
	}
	T& operator*(){
		return *ptr;
	}

	// Do not allow to duplicate:
	UniquePointer(UniquePointer const& other) = delete;
	UniquePointer& operator=(UniquePointer const& other) = delete;

	// Delete when out of scope:
	~UniquePointer(){ 
		if (ptr) delete ptr; 
	}

	// Move constructor and operator=:
	UniquePointer(UniquePointer&& other){
		*this=move(other);
	}
	void operator=(UniquePointer&& other){
		ptr=other.ptr;
		other.ptr=nullptr;
	}
};
