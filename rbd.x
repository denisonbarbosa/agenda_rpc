struct ContactEntry {
          string name<32>;
          string phone<32>;
          string address<64>;
          string email<32>;
};

program RBDPROG{
    version RDBVERS{
          int INSERT(ContactEntry) = 1;
          int REMOVE(string) = 2;
          ContactEntry SEARCH(string) = 3;
    } = 1;
} = 0x30090949;
