
#include "Core.h"
#include <iostream>
#include <locale.h>

int     main() {
    setlocale(LC_ALL, "");
    Core    core;

    core.Start();
    return (0);
}