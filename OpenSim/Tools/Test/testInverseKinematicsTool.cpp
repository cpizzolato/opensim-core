#include "OpenSim/Tools/InverseKinematicsTool.h"
#include "OpenSim/Simulation/MarkersReference.h"
#include "OpenSim/Common/IO.h"
#include <iostream>
#include <string>
using std::string;
using OpenSim::InverseKinematicsTool;

int main() {
    /*This is not a proper test, as the only way I have been able to isolate the
    problem I have noticed is to add a `cout` at the end of
    `MarkersReference::updateInternalWeights`. This main simply executes the
    `InverseKinematicsTool` using on a test setup file. In the setup file, all
    the marker weights are set to 1, except for Top.Head, which is set to 10. */
    try {
        string ikSetupFilename("subject01_IK_setup.xml");
        OpenSim::IO::chDir(BASE_DIR);
        InverseKinematicsTool ikTool(ikSetupFilename);
        //Uncomment the following line to check the marker weights in the
        //xml setup file
        // std::cout << ikTool.dump() << std::endl;

        /*When executing `ikTool.run()`, the function
        `MarkersReference::updateInternalWeights` eventually called.I have added
        a `cout` at the end of that function.
        */
        ikTool.run();

        /*
        The following is the output you should see on `cout`,
        showing the weights of the markers actually used by 
        `MarkersReference`. You can see how R.Wrist.Med is set to 10
        while Top.Head is set to 1, which is different from what the
        XML specifies. 

        R.ASIS: 1
        L.ASIS: 1
        V.Sacral: 1
        R.Thigh.Upper: 1
        R.Thigh.Front: 1
        R.Thigh.Rear: 1
        L.Thigh.Upper: 1
        L.Thigh.Front: 1
        L.Thigh.Rear: 1
        R.Shank.Upper: 1
        R.Shank.Front: 1
        R.Shank.Rear: 1
        L.Shank.Upper: 1
        L.Shank.Front: 1
        L.Shank.Rear: 1
        R.Heel: 1
        R.Midfoot.Sup: 1
        R.Midfoot.Lat: 1
        R.Toe.Tip: 1
        L.Heel: 1
        L.Midfoot.Sup: 1
        L.Midfoot.Lat: 1
        L.Toe.Tip: 1
        Sternum: 1
        R.Acromium: 1
        L.Acromium: 1
        R.Bicep: 1
        L.Bicep: 1
        R.Elbow: 1
        L.Elbow: 1
        R.Wrist.Med: 10
        R.Wrist.Lat: 1
        L.Wrist.Med: 1
        L.Wrist.Lat: 1
        R.Toe.Lat: 1
        R.Toe.Med: 1
        L.Toe.Lat: 1
        L.Toe.Med: 1
        R.Temple: 1
        L.Temple: 1
        Top.Head: 1
        */

    }
    catch (OpenSim::Exception& e) {
        e.print(std::cout);
    }
e     return 0;
}