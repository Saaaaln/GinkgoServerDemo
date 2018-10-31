enum column_type{
 INT,
 FLOAT,
 DOUBLE,
 STRING,
}

struct Attribute{
 1: string attrName,
 2: column_type attrType,
}


struct TTableDescriptor {
    1: string tableName,
    2: list<Attribute> attributes,
}

service Ginkgo {
 list<TTableDescriptor> get_tables_meta(),
 TTableDescriptor get_table_descriptor(1: string table_name),
}