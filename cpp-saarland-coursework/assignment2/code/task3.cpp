#include <iostream>  
#include <fstream>    
#include <vector>     
#include <string>     
#include <cstdlib>    
#include <cmath>      

// Define a simple structure to hold gene info
struct Gene {
    std::string chrom;  
    int start;          
    int stop;            
    int middle;          
    int cluster_id;      
};

// Helper function to compute middle point
int compute_middle(int start, int stop) {
    return (start + stop) / 2;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./task3 input.txt distance output.txt\n";
        return 1;
    }


        std::ifstream infile(argv[1]);
    int allowed_distance = std::stoi(argv[2]);
    std::ofstream outfile(argv[3]);

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening input or output file.\n";
        return 1;
    }
    
    std::vector<Gene> genes;
    std::string chrom, prev_chrom = "";
    int start, stop, prev_start = -1;

        // Read input and build gene list
    while (infile >> chrom >> start >> stop) {
        if (!prev_chrom.empty()) {
            if (chrom < prev_chrom || (chrom == prev_chrom && start < prev_start)) {
                std::cerr << "Input not sorted. Exiting.\n";
                return 1;
            }
        }
        genes.push_back({chrom, start, stop, compute_middle(start, stop), 0});
        prev_chrom = chrom;
        prev_start = start;
    }

        // Assign clusters
    int current_cluster = 1;
    for (size_t i = 0; i < genes.size(); ++i) {
        if (i == 0) {
            genes[i].cluster_id = current_cluster;
        } else {
            if (genes[i].chrom != genes[i - 1].chrom) {
                // If chromosome changed → new cluster
                ++current_cluster;
                genes[i].cluster_id = current_cluster;
            } else {
                int dist = std::abs(genes[i].middle - genes[i - 1].middle);
                if (dist <= allowed_distance) {
                    // Close enough → same cluster
                    genes[i].cluster_id = genes[i - 1].cluster_id;
                } else {
                    // Too far → start new cluster
                    ++current_cluster;
                    genes[i].cluster_id = current_cluster;
                }
            }
        }
    }

        // Write output file
    for (const auto& gene : genes) {
        outfile << gene.chrom << "\t"
                << gene.start << "\t"
                << gene.stop << "\t"
                << "cluster=" << gene.cluster_id << "\n";
    }

    return 0;
}
