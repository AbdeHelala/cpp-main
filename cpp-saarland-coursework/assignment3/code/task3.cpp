#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Check if character is a valid DNA base
bool is_valid_base(char c) {
    char uc = toupper(c);
    return uc=='A' || uc=='C' || uc=='G' || uc=='T';
}

// Extract n-skip-k-mers
vector<string> extract_kmers(const string& seq, size_t k, size_t n) {
    vector<string> kmers;
    size_t step = n+1, span=(k-1)*step+1;
    if(seq.size()<span) return {};
    for(size_t i=0;i+span<=seq.size();++i){
        string kmer;
        for(size_t j=0;j<k;++j)
            kmer += toupper(seq[i+j*step]);
        kmers.push_back(kmer);
    }
    return kmers;
}

// Process one FASTA entry
void process_sequence(const string& header, const string& seq, size_t k, size_t n) {
    // Validate
    if(!all_of(seq.begin(), seq.end(), is_valid_base)) {
        // print header *without* '>' to stderr
        cerr << header.substr(1) << "\n";
        return;
    }
    // Extract & count
    auto kmers = extract_kmers(seq, k, n);
    if(kmers.empty()) return;  // sequence too short → nothing to print

    unordered_map<string,int> counts;
    for(auto& km:kmers) ++counts[km];

    // print to stdout
    cout << header.substr(1) << "\n";
    map<string,int> sorted(counts.begin(), counts.end());
    for(auto& p: sorted) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main(int argc, char* argv[]) {
    if(argc!=4) {
        cerr<<"Usage: ./task3 <fasta_file> <k> <n>\n";
        return 1;
    }

    string fasta = argv[1];
    size_t k = stoul(argv[2]);
    size_t n = stoul(argv[3]);

    ifstream in(fasta);
    if(!in) {
        cerr<<"Error: Cannot open input file.\n";
        return 1;
    }

    string line, header, seq;
    while(getline(in,line)) {
        if(line.empty()) continue;
        if(line[0]=='>') {
            if(!header.empty()) {
                process_sequence(header, seq, k, n);
            }
            header = line;
            seq.clear();
        } else {
            seq += line;
        }
    }
    // last one
    if(!header.empty()) process_sequence(header, seq, k, n);

    return 0;
}
