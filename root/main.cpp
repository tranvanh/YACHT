#include "GuiLib/Application.h"
#include "PacmanApp/PacmanApplication.h"

std::shared_ptr<YACHT::PACMAN::PacmanApplication> createPacmanApplication() {
    return std::make_shared<YACHT::PACMAN::PacmanApplication>();
}

int main() {
    std::shared_ptr<YACHT::Application> application = createPacmanApplication();
    CASSERT(application.get(), "Application failed to initialize");
    application->run();
    return 0;
}