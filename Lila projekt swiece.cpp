#include "file_handle.h"

using namespace std;

int main() {
    Map test = read("intc_us_d.csv");
    test.show();
  
    return 0;
}