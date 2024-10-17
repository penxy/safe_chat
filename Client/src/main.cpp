#include "C_Args.h"
#include "Tool/list.h"
#include "C_Conf.h"


int main(int argc,char **argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    C_Conf::get_inst().init(FLAGS_confile);

      




    return 0;
}
