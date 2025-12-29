cmake_minimum_required(VERSION 3.25)
project(My_first_project C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0074 NEW)

add_executable(sorting_station src/works_on_C/more_difficult/sorting_station.c)
add_executable(advanced_bracket-2 src/works_on_C/more_difficult/advanced_bracket-2.c)

add_executable(counting_rhyme src/works_on_C/more_difficult/counting_rhyme.c)
add_executable(sorting_list src/works_on_C/more_difficult/sorting_list.c)

add_executable(main src/works_on_C/more_difficult/optimal_sorting/main.c)

add_executable(check_string src/works_on_C/check_string.c)
add_executable(count_zero src/works_on_C/count_zero.c)
add_executable(find_string src/works_on_C/find_string.c)

add_executable(Lucky tickets src/works_on_C/Lucky tickets.c)
add_executable(array_flip src/works_on_C/array_flip.c)
add_executable(incomplete_quotient src/works_on_C/incomplete_quotient.c)
add_executable(fast_count src/works_on_C/fast_count.c)

