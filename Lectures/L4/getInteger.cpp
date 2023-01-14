int getInteger(string prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        stream >> value >> ws;
        if (!stream.fail() && stream.eof()) {
            break;
        }
        cout << "Illegal integer format. Try again." << endl;
    }
}
