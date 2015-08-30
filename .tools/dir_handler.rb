class DirHandler
  attr_reader :paths

  def initialize dir, extension
    @paths = list_paths_recursively dir, extension
  end

  def on_each_line!
    @paths.each do |path|
      content = File.readlines path
      content.each { |line| yield line }
      write_back path, content 
    end
  end  

private
  def list_paths_recursively dir, extension
    Dir.glob "#{ dir }/**/*.#{ extension }"
  end

  def write_back filename, content
    File.open(filename, 'w+'){ |file| file.puts content }
  end
end
