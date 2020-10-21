# Day 2

## Todo
1. refresh move semantics, lambdas (covered topics)
    * check for the trvial and non trivial classes
    * Check copy constrcutor for trivial and non trivial casses
    * Algorithms and Lamda(https://en.cppreference.com/w/cpp/algorithm)
    * Apply all this concepts  
2. explore STL algorithms, apply in coding tasks with lambdas
3. self study (try) -- file handling -- ofstream, ifstream
4. pre-read
    std::bind
    some topics on templates
    smart pointers
5. vs setup for code style,visulaization and analysis


## Notes

1. Type of Objects
    * Trvial and Non Trivial Objects
    Trivial Copy constructor is given by the compiler

2. Move Schematics(Move Constr)
    * In Scenario the dublicate heap blocks are created
    * best convention is to transfer the heap block
    *   move assignment is done for the Temp objects and Named objects by type casting
    *   perfect forwarding
    *   to call l-value and r-value dedicated

3. Lamdas 
    * used to write temporary function
    * Lambdas for effective callback mechanism, without the need for defining named functions inadvance
    * 

    int Banking::countAccountsWithMinBal(double minval) {
    int count=0;
    count = std::count_if(accounts.begin(), accounts.end(),
                                        [minval](const Account& ref) {
        return ref.getBalance() > minval;
    });
    return count;
    }

    double Banking::findAccountWithMaBalance() {

    

    auto iter = std::maxval(accounts.begin(), accounts.end(), 
                    [](const Account& r1, const Account& r2) {
                        return r1.getBalance() < r2.getBalance();
    });
    }



## Study List
* function pointer
* heap block
* return value optimization
* clang or google (code style)
* C++ tutor,Source Trails(Visualize)
* Codacy(Analize)
