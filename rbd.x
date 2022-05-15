struct ContactEntry {
          string name<32>;
          string phone<32>;
          string address<64>;
          string email<32>;
};

struct SearchResult {
    bool found;
    ContactEntry* entry;
};

program RBDPROG{
    version RDBVERS{
          int INSERT(ContactEntry) = 1;
          int REMOVE(string) = 2;
          SearchResult SEARCH(string) = 3;
    } = 1;
} = 0x30090949;
