import sublime_plugin, os

class terminalCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        try:
            dire = os.path.dirname(self.view.file_name())
            execute = dire[0] + ": && cd " + dire + " && start"
            os.system(execute)
        except:
            os.system("pushd d:/dhiraj/Programming && start")