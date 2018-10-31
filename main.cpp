#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


struct ProjDescriptor{

}


struct SpineLock{

}

struct WRLock{

}

struct TableFileConnector{

}


struct TTableMeta {
    1: string tableName,
    2: vector<Attribute> attributes,
//    3: TableID table_id_,
//    4: vector<ProjDescriptor> projection_list_,
//    5: i64 row_number_,
//    6: bool has_deleted_tuples_,
//    7: map<int, map<int, vector<uint32_t>>> meta_len_,
//    8: map<int, map<int, vector<uint64_t>>> meta_start_pos_,
//    9: map<int, map<int, vector<uint64_t>>> file_len_,
//    10: int file_num_,
//    11: vector<vector<uint64_t>> logical_files_length_,
//    12: SpineLock update_lock_,
//    13: WRLock wr_lock_,
//    14: TableFileConnector* write_connector_ = NULL,
}

        service Ginkgo {
list<TTableMeta> get_tables_meta;
TTableDescriptor get_table_descriptor(1: TSessionId session, 2: string table_name)
User get(1: string uid),
}