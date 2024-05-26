#include "MainWindow.h";

using namespace CPQ;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainWindow());
    return 0;
}
