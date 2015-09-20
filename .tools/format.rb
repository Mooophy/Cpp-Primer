require_relative 'dir_handler'

class Format
  attr_reader :dir, :extensions

  def initialize dir, extensions
    @dir = dir
    @extensions = extensions
    @dir.freeze
    @extensions.freeze
    @handlers = extensions.collect{ |e| DirHandler.new dir, e }
  end

  # 1,2,3,4  => 1, 2, 3, 4
  def for_commas
    each_line! do |line|   
      begin
        line.gsub! /,(\S)/, ', \1' unless line.match /.*\".*,.*\".*/ or line.match /','/
      rescue Exception => e
        puts e.message + ", ignored."
      end
    end
  end 
 
  # {foo} => { foo }
  def for_curly_brackets
    for_pairs '{', '}'
  end

  # bug inside, still working on
  def for_if_blocks
    pattern = /\n(\s*)if(\s*)\((.*)\)(?!\n){(.*)(\n+)(.*)}(\s*)/
    replacement = "\n" + '\1if (\3)' + "\n" + '\1{\3\4\5}\6' 
    each_file! { |file| file.gsub! pattern, replacement }
  end
 
  private
  def each_line!
    @handlers.each do |h|
      h.on_each_line! { |line| yield line }
    end
  end

  def each_file!
    @handlers.each do |h|
      h.on_each_file! { |file| yield file }
    end
  end

  def for_pairs open, close
    each_line! do |line|
      begin 
        if line.match /#{ open + ".*" + close }/ 
          line.gsub! /#{ open   + "(\S)"}/,   open + ' \1'
          line.gsub! /#{ "(\S)" + close }/,   '\1 '+ close
        end
      rescue Exception => e
        puts e.message + ", ignored."
      end
    end
  end
end    

format = Format.new ARGV[0], [ "cpp", "h", "hpp", "md" ]
format.for_commas
format.for_curly_brackets
format.for_if_blocks
