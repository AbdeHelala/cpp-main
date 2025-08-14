#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

// Processes a single FASTA record, filters, and computes next permutation
void processRecord(const std::string& raw, std::vector<std::string>& results) {
    if (raw.empty()) return;

    bool hasU = false, hasT = false;
    for (char c : raw) {
        char u = std::toupper(c);
        if      (u == 'U') hasU = true;
        else if (u == 'T') hasT = true;
        else if (u != 'A' && u != 'C' && u != 'G')
            return;  // invalid char or stray \r → drop
    }
    if (hasU && hasT) return; // mixed RNA/DNA → drop

    // Convert U to T if needed
    std::string seq = raw;
    if (hasU) {
        for (char& c : seq)
            if (std::toupper(c) == 'U')
                c = 'T';
    }

    // Compute next permutation
    if (std::next_permutation(seq.begin(), seq.end()))
        results.push_back(seq);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <fasta_file>\n";
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Error: cannot open file " << argv[1] << "\n";
        return 1;
    }

    std::vector<std::string> results;
    std::string line, buffer;

    while (std::getline(in, line)) {
        // Strip Windows CR if present
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (!line.empty() && line[0] == '>') {
            // Process the record we've built so far
            processRecord(buffer, results);
            buffer.clear();
        } else {
            buffer += line;
        }
    }
    // Final record at EOF
    processRecord(buffer, results);

    // Sort by length, then lexicographically
    std::sort(results.begin(), results.end(),
         [](const std::string &a, const std::string &b) {
             if (a.size() != b.size()) return a.size() < b.size();
             return a < b;
         });

    // Print one per line
    for (const auto& s : results)
        std::cout << s << "\n";
    return 0;
}