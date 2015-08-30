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

  def for_commas
    each_line do |line|   
      begin
        line.gsub! /,(\S)/, ', \1' unless line.match /.*\".*,.*\".*/ or line.match /','/
      rescue Exception => e
        puts e.message + ", ignored."
      end
    end
  end 
 
  def for_curly_brackets
    count = 0
    each_line do |line|
      begin 
        if line.match /{.*}/ 
          puts (count += 1).to_s; puts line
          line.gsub! /{(\S)/, '{ \1'
          line.gsub! /(\S)}/, '\1 }'
        end
      rescue Exception => e
        puts e.message + ", ignored."
      end
    end
  end
 
  private
  def each_line
    @handlers.each do |h|
      h.on_each_line { |line| yield line }
    end
  end
end    

format = Format.new ARGV[0], [ "cpp", "h", "hpp", "md" ]
format.for_commas
format.for_curly_brackets
