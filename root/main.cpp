#include "GuiLib/Application.h"
#include "PacmanApp/PacmanApplication.h"
#include <cassert>
#include <memory>

std::shared_ptr<PacmanApplication> createPacmanApplication() {
    return std::make_shared<PacmanApplication>();
}

int main() {
    std::shared_ptr<Application> application = createPacmanApplication();
    assert(application);
    application->run();
    return 0;
}