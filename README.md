# C++ Syntax
**Bit Field Syntax**
```
struct S
{
    // will usually occupy 2 bytes:
    unsigned char b1 : 3; // 1st 3 bits (in 1st byte) are b1
    unsigned char    : 2; // next 2 bits (in 1st byte) are blocked out as unused
    unsigned char b2 : 6; // 6 bits for b2 - doesn't fit into the 1st byte => starts a 2nd
    unsigned char b3 : 2; // 2 bits for b3 - next (and final) bits in the 2nd byte
};
```

**bool bWholeWorldNavigable vs uint32 bWholeWorldNavigable:1**
- uint32 bWholeWorldNavigable:1 uses 1 bit
- bool bWholeWorldNavigable (usually) uses 1 byte

**Scoped Enumeration vs Namespace Scope for Enums:**
```
namespace EBTNodeResult
{
	enum Type : int
	{
		Succeeded,
		Failed,
		Aborted,
		InProgress,
	};
}

EBTNodeResult::Succeeded

namespace EBTNodeResultScoped
{
	enum class Type : int
	{
		Succeeded,
		Failed,
		Aborted,
		InProgress,
	};
}

EBTNodeResultScoped::Type::Succeeded
```

**nullptr vs NULL**
- nullptr introduced in C++11
- nullptr is literall value of std:nullptr_t type, which is convertible to any other pointer
- NULL is (usually) a macro for the integer 0.

**return nullptr in templated function**
```
	template<typename TNavSys>
	FORCEINLINE TNavSys* GetCurrent(UWorld* World)
	{
		return World ? Cast<TNavSys>(World->GetNavigationSystem()) : (TNavSys*)nullptr;
	}
```
notice the cast ```(TNavSys*)nullptr```. It's necessary

**FText(FString &&sourceString): What is && here**
Rvalue Reference (&&).
Move Semantics: When you pass an object to a function using an rvalue reference, the function can take over ownership of the resources of that object. This is called "moving" the object, and it avoids unnecessary copying of data, especially beneficial for objects that manage dynamic memory.


**UE: MoveTemp ?**
MoveTemp will cast a reference to an rvalue reference. UE's equivalent of std::move except that it will not compile when passed an rvalue or const object, because we would prefer to be informed when MoveTemp will have no effect.

**C++ Copy-and-Swap idiom**
```
    // Assignment operator
    MyClass& operator=(MyClass other) { // Note: other is passed by value
        swap(*this, other);  // Swap contents with the temporary copy
        return *this;
    }

    // Swap function (can be friend or member)
    friend void swap(MyClass& first, MyClass& second) noexcept {
        using std::swap;
        // Swap internal states of first and second
    }
```

extra: going out of fashion after the introduction of &&

**Self-Assignment Problem in C++**
```
    MyClass& operator=(const MyClass& other) {
        delete[] data;          // Free existing resource
        data = new int[...];    // Allocate new resource
        std::copy(...);         // Copy data from 'other'
        return *this;
    }
```

This will crash. Either 1) Check for this!=&other or 2) use Copy-and-Swap Idiom
Move semantics make the Self-Assignment Problem less common

**pimpl, ?**
- Encapsulation: It hides the implementation details of a class, exposing only the necessary interface in the header file. This helps in maintaining a clear separation between the interface and implementation.

- Reduce Compilation Dependencies: By hiding implementation details in a source file, changes to the implementation don't require recompiling the classes that use it, as long as the interface remains unchanged. This can significantly reduce build times in large projects.

- ABI Stability: It helps in maintaining binary compatibility (ABI) across different versions of a library, as changes to private members don't affect the externally visible class layout.

**forwarding reference (universal reference)?**
- T&&
- Example:

```
void someFunction(int& arg) {
    std::cout << "Lvalue overload called\n";
}

void someFunction(int&& arg) {
    std::cout << "Rvalue overload called\n";
}

template<typename T>
void wrapper(T&& arg) {
    someFunction(std::forward<decltype(arg)>(arg));
}

int main() {
    int a = 5;
    wrapper(a);  // Calls the lvalue overload of someFunction
    wrapper(10); // Calls the rvalue overload of someFunction
}
```


