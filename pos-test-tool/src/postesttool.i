/* file: postesttool.i */
%module postesttool
 %{
 /* Put header files here or function declarations like below */
 #include "postesttool.h"
 #include "model/posobject.h" 
%}

%include <std_string.i>

/* list functions to be interfaced: */
class PosTestTool
{
public:
    PosTestTool(PosModel device);

    void insertCard();

    void removeCard();

    void keyPress(std::string key);

    void write(std::string text);

    void showScreen();

    bool isIdle();
};

enum class PosModel {
    PAX_S920
};
