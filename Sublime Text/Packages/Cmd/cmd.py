import sublime_plugin, os

class CmdCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        try:
            dire = os.path.dirname(self.view.file_name())
            execute = dire[0] + ": && cd " + dire + " && start cmd"
            os.system(execute)
        except:
            # default path
            os.system("pushd d: && start")