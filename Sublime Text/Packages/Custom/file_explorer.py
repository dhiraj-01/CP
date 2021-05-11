import sublime_plugin, os

class file_explorerCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        try:
            dire = os.path.dirname(self.view.file_name())
            execute = dire[0] + ": && cd " + dire + " && start ."
            os.system(execute)
        except:
            os.system("start d:/dhiraj/Programming")