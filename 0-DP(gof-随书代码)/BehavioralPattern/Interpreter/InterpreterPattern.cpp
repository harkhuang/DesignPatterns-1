/*******************************************************************
 * File         :   interpreter-pattern.cpp (interpreter design pattern c++ example)
 * Author       :   Saurabh Gupta
 * Description  :   CInterpreter processes commands and performs actions
 *                  based on its input. Here we create a simple command
 *                  language consisting of single characters.
 * Date         :   PM 05:20 29 December 2011
 * Source       :   http://www.ccplusplus.com/2011/07/design-pattern-guide-with-example-and.html
 * Note         :
 ******************************************************************/
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class CInterpreter
{
public:
    template<typename It>
    void m_run(It from, It to){
        for(It i=from; i!=to; ++i){
            switch(*i){
            case 'h':
                cout << "Hello";
                break;
            case ' ':
                cout << ' ';
                break;
            case 'w':
                cout << "world";
                break;
            case '!':
                cout << '!';
                break;
            case 'n':
                cout << endl;
                break;

            default:
                throw runtime_error("Unknown command");
            }
        }
    }
 };


void helloworld(const string & script)
{
    CInterpreter().m_run(script.begin(), script.end());
}


int main()
{
    helloworld("h w!n");
    return 0;
}

/*
 * OUTPUT
 *
 [sgupta@rhel6x64 interpreter]$ c++ interpreter-pattern.cpp -o interpreter-pattern
 [sgupta@rhel6x64 interpreter]$ ./interpreter-pattern
 Hello world!
 [sgupta@rhel6x64 interpreter]$
*/
