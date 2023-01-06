#!/bin/bash

EOC="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"

#----- Path to containers hpp files -----
CONTAINER_PATH="./includes"

#----- Compilation parameters -----
CXX="c++"
CXXFLAGS="-Wall -Wextra -Werror -std=c++98"
INCLUDES="-I${CONTAINER_PATH} -I."

#----- Printer functions -----
center() {
  termwidth="$(tput cols)"
  padding="$(printf '%0.1s' ={1..500})"
  printf "${BOLD}${YELLOW}%*.*s %s %*.*s${EOC}\n" \
  0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"
}
print_test_info(){
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))
    fill=$(printf '%0.1s' ={1..500})

    printf "${BOLD}${YELLOW}|%-*s|%-*s|%-*s|${EOC}\n" \
        $field1 "Test" $field2 "Compile" $field3 "Diff"
    printf "${BOLD}${YELLOW}%-.*s${EOC}\n" $columns $fill

}

print_fail() {
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))

    printf "|${RED}%-*s${EOC}|${GREEN}${BOLD}%-*s${EOC}|${RED}${BOLD}%-*s${EOC}|\n" \
        $field1 "$1" $field2 "OK" $field3 "KO"
}

print_error_compile() {
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))

    printf "|${RED}%-*s${EOC}|${RED}${BOLD}%-*s${EOC}|${RED}${BOLD}%-*s${EOC}|\n" \
        $field1 "$1" $field2 "KO" $field3 "KO"
}

print_success() {
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))

    printf "|${GREEN}%-*s${EOC}|${GREEN}${BOLD}%-*s${EOC}|${GREEN}${BOLD}%-*s${EOC}|\n" \
        $field1 "$1" $field2 "OK" $field3 "OK"
}

compile() {
    # 1=file 2={ft/std} 3=output_file 4?=compile_log
	compile_cmd="${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=${2} -o ${3} ${1} srcs/memory_tracker.cpp srcs/leak_checker.cpp"
	# if not debug mode?
    if [ -n "$4" ]; then
		compile_cmd+=" &>${4}"
	fi
	eval "${compile_cmd}"
	return $?
}

print_elapsed_time() {
    #$1 = ft elapsed time
    #$2 = std elapsed time
    columns=$(tput cols)
    printf "| Ft_elapsed_time: %s  | Std_elapsed_time: %s |\n" $1 $2   
}

# ----- Run one test -----
run_one_test(){
    container=$1
    test_name=$2
    file=$3
    debug=$4

	ft_bin="ft.$container.out"; 
    ft_log="logs/$container/ft/$test_name.log"
	std_bin="std.$container.out";
    std_log="logs/$container/std/$test_name.log"

	# Launch async compilations for ft/std binaries
	compile "$3" "ft"  "$ft_bin" & ft_pid=$!;
	compile "$3" "std" "$std_bin" & std_pid=$!;

    # ----- wait for compilation to finish -----
	wait ${ft_pid}; ft_ret=$?;
	wait ${std_pid}; std_ret=$?;

	> $ft_log; > $std_log;
	# Starting async binaries execution (if compilation succeeded)
	if [ ${ft_ret} -eq 0 ]; then
        ft_start_time=$(date +%s%N);
		./${ft_bin} &>${ft_log} &
		ft_pid=$!;
	fi
	if [ ${std_ret} -eq 0 ]; then
        std_start_time=$(date +%s%N);
        ./${std_bin} &>${std_log} &
		std_pid=$!;
	fi

	# Waiting binaries execution (if compilation succeeded)
	if [ "${ft_ret}" -eq 0 ]; then
		wait ${ft_pid}; 
        ft_ret=$?;
        ft_elapsed_time=$((($(date +%s%N) - $ft_start_time)/1000000));
	fi
	if [ "${std_ret}" -eq 0 ]; then
        std_elapsed_time=$((($(date +%s%N) - $std_start_time)/1000000));
		wait ${std_pid};
        std_ret=$?;
	fi

	#__ Diff file __
    diff_file="./diffs/$1/${test_name}.diff"
    diff -u $ft_log $std_log > $diff_file
    res=$(cat $diff_file | wc -l)
    if [ $res -ne "0" ]; then
        print_fail "$container $test_name"
    else
        print_success "$container $test_name"
        # print_elapsed_time $ft_elapsed_time $std_elapsed_time
        rm -f $diff_file
    fi

    rm $ft_bin
    rm $std_bin
}
# #----- Executes one test -----
# run_test() {
#     container=$1
#     test_name=$2
#     file=$3
#     debug=$4
    
#     if [ "$debug" = true ]; then
#         #__ Test for ft and std__
#         for namespace in ft std; do
#             if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=$namespace -o ${file%.*} $file srcs/memory_tracker.cpp srcs/leak_checker.cpp; then
#                 if ! ${file%.*} > ./logs/$1/$namespace/${test_name}.log; then
#                     print_fail "$1 ${test_name}"
#                     return
#                 fi
#             else
#                 print_error_compile "$container $test_name"
#                 return
#             fi
#             rm ${file%.*}
#         done
#     else
#         #__ Test for ft and std__
#         for namespace in std ft; do
#             if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=$namespace -o ${file%.*} $file srcs/memory_tracker.cpp srcs/leak_checker.cpp 2> /dev/null; then
#                 if ! ${file%.*} > ./logs/$1/$namespace/${test_name}.log; then
#                     print_fail "$1 ${test_name}"
#                     return
#                 fi
#             else
#                 print_error_compile "$container $test_name"
#                 return
#             fi
#             rm ${file%.*}
#         done
#     fi

#     #__ Diff file __
#     diff_file="./diffs/$1/${test_name}.diff"
#     diff -u ./logs/$1/ft/${test_name}.log ./logs/$1/std/${test_name}.log > $diff_file
#     res=$(cat $diff_file | wc -l)
#     if [ $res -ne "0" ]; then
#         print_fail "$container $test_name"
#     else
#         print_success "$container $test_name"
#         rm -f $diff_file
#     fi
# }

#----- For a given container executes tests for ft and std -----
test_container() {
    #----- Creates log and diff folder if not exist -----
    mkdir -p ./logs/$1/ft
    mkdir -p ./logs/$1/std
    mkdir -p ./diffs/$1/

    center $(echo $1 | tr '[:lower:]' '[:upper:]')
    print_test_info

    files=$(find "tests/$1" -type f -name '*.cpp' 2>/dev/null | sort )

    if [ ${#files} == 0 ]; then
        echo "No tests found for container $1"
        return
    fi

    for file in $files
    do 
        test_name=$(basename ${file%.*})
        # run_test $1 $test_name $file
        run_one_test $1 $test_name $file
    done        
}

#----- Tests all containers -----
test_containers() {

    containers="vector stack map set"

    for i in $containers;
    do
        test_container $i
    done
}

$*