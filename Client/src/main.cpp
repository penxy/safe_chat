#include "C_Args.h"
#include "Tool/list.h"
#include "C_Conf.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main(int argc,char **argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    C_Conf::get_inst().init(FLAGS_confile);

      

    

    return 0;
}
