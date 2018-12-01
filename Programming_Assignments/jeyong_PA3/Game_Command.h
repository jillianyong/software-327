#ifndef Game_Command_h
#define Game_Command_h

#include "Model.h"
#include "View.h"

class Model;

void do_move_command(Model& mod);
void do_work_command(Model& mod);
void do_deposit_command(Model& mod);
void do_stop_command(Model& mod);
void do_lock_command(Model& mod);
void do_go_command(Model& mod);
void do_run_command(Model& mod);
void do_quit_command(Model& mod);
void main_loop(Model& mod, View& views);

#endif