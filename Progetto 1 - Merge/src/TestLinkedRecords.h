
#ifndef PROGETTO1_TESTLINKEDRECORDS_H
#define PROGETTO1_TESTLINKEDRECORDS_H
//__________Check_new_____________________________________________________________
void Check_new_nullpointer();
void Check_new_head();
void Check_new_tail();
void Check_new_len();
//__________________________________________________________________________________

//___________Node_new_______________________________________________________________
void Node_new_nullpointer();
void Node_new_record();
void Node_new_next();
void Node_new_prev();
//_________________________________________________________________________________

//_________List_Free________________________________________________________________
void List_free_test();
//__________________________________________________________________________________

//__________Get_record_in_pos_______________________________________________________
void Test_Get_record_in_pos(int iterations);
//__________________________________________________________________________________

//___________Add_record_____________________________________________________________
void Add_record_size(int iterations);
void Add_record_tail(int iterations);
void Add_record_reverse(int iterations);
//__________________________________________________________________________________

//________Add_record_in_pos_________________________________________________________
void Add_record_in_pos_first(int iterations);
void Add_record_in_pos_last(int iterations);
void Add_record_in_pos_middle(int iterations);
//__________________________________________________________________________________

//___________Remove_last_record_____________________________________________________
void Remove_last_record_sizetail(int iterations);
void Remove_last_record_integrity(int iterations);
//__________________________________________________________________________________

//________________Remove_record_in_pos________________________________________________
void Remove_record_in_pos_head(int iterations);
void Remove_record_in_pos_tail(int iterations);
void Remove_record_in_pos_middle(int iterations);
void Remove_record_in_pos_integrity_head(int iterations);
void Remove_record_in_pos_integrity_tail(int iterations);
void Remove_record_in_pos_integrity_middle(int iterations);
void Full_test(int iterations);

//____________________________________________________________________________________
#endif //PROGETTO1_TESTLINKEDRECORDS_H
