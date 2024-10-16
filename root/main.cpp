#include "CoreLib/Common.h"
#include "GuiLib/Application.h"
#include "PacmanApp/PacmanApplication.h"

std::shared_ptr<PacmanApplication> createPacmanApplication() {
    return std::make_shared<PacmanApplication>();
}

int main() {
    std::shared_ptr<Application> application = createPacmanApplication();
    CASSERT(application.get(), "Application failed to initialize");
    application->run();
    return 0;
}