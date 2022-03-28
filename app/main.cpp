/*
** EPITECH PROJECT, 2021
** B-YEP-400-STG-4-1-indiestudio-dorian.schlosser
** File description:
** main
*/

#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>

#include "../include/core.hpp"

int main()
{
    std::unique_ptr<Core> core = std::make_unique<Core>();
    core->initialization();
    core->core_loop();
    core->close_loop();
    return (EXIT_SUCCESS);
}