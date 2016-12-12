#include "OpenSim/Tools/InverseKinematicsTool.h"
#include "OpenSim/Simulation/MarkersReference.h"
#include "OpenSim/Common/IO.h"
#include <iostream>
#include <string>
using std::string;
using OpenSim::InverseKinematicsTool;

int main() {
    try {
        string ikSetupFilename("subject01_IK_setup.xml");
        OpenSim::IO::chDir(BASE_DIR);
        InverseKinematicsTool ikTool(ikSetupFilename);
        ikTool.run();
        string dump = ikTool.dump();
        std::cout << dump;
    }
    catch (OpenSim::Exception& e) {

        e.print(std::cout);
    }
    return 0;
}