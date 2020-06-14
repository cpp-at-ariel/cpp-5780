/**
 * A demo implementation of a shared pointer.
 * 
 * Author: Eran Kaufmann
 * Since:  2020-06
 */

template<typename T> class SharedPointer{

	struct Ret{
		T* ptr=nullptr;
		int rc=0;
	};

	Ret* ret = new Ret;

public:

	SharedPointer()=default;
	SharedPointer(T* t){ret -> ptr=t; ret->rc++;};
	auto operator->(){
		return ret->ptr;
	}
	SharedPointer(SharedPointer const& other){ret->ptr = other.ret->ptr; ret->rc++ ;};
	SharedPointer& operator=(SharedPointer const& other) {ret->ptr = other.ret->ptr; ret->rc++ ;};

	~SharedPointer(){
		ret -> rc--;
		if(ret -> rc == 0)
			delete ret->ptr;
	}
	SharedPointer(SharedPointer&& other){
		*this=move(other);
	}
	void operator=(SharedPointer&& other){
		ret->ptr=other.ret->ptr;
	}

};
