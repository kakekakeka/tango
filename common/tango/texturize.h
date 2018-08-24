#ifndef TANGO_TEXTURIZE_H
#define TANGO_TEXTURIZE_H

#include <tango_3d_reconstruction_api.h>
#include "data/dataset.h"
#include "gl/opengl.h"

namespace oc {

    class TangoTexturize {
    public:
        TangoTexturize();
        void Add(Tango3DR_ImageBuffer t3dr_image, std::vector<glm::mat4> matrix, Dataset dataset);
        void ApplyFrames(Dataset dataset, std::string filename);
        void Clear(Dataset dataset);
        std::string GetEvent() { return event; }
        Image* GetLatestImage(Dataset dataset);
        int GetLatestIndex(Dataset dataset);
        std::vector<glm::mat4> GetLatestPose(Dataset dataset);
        bool Init(std::string filename, Tango3DR_CameraCalibration* camera);
        bool Init(Tango3DR_ReconstructionContext context, Tango3DR_CameraCalibration* camera);
        void Process(std::string filename);
        void SetEvent(std::string value) { event = value; }
        void SetResolution(float value) { resolution = value; }

    private:
        void CreateContext(bool finalize, Tango3DR_Mesh* mesh, Tango3DR_CameraCalibration* camera);

        int poses;
        float resolution;
        std::string event;
        Tango3DR_TexturingContext context;
        int width, height;
    };
}
#endif
