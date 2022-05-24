#include <app.hpp>

int main(){
    app app;
    while(app.isRunning()){
        app.update();
        app.render();
    }

    return 0;
}