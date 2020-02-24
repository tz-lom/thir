from conans import ConanFile

class Thir(ConanFile):
    settings = "os"
    generators = "cmake"
    
    def requirements(self):
        if self.settings.os == "Windows":
            self.requires("boost/1.72.0")
        self.requires("gtest/1.8.1")
