require_relative 'dir_handler'

#extensions = [ "cpp", "h", "hpp", "md" ]
#extensions.freeze
#dir = ARGV[0] 
#dir.freeze
#
##init handlers for all types of files
#handlers = extensions.collect{ |e| DirHandler.new dir, e }
#
##for comma:
##   1,2,3,4   =>  1, 2, 3, 4
#handlers.each do |h|
#  h.on_each_line do |line| 
#    begin
#      line.gsub! /,(\S)/, ', \1' unless line.match /.*\".*,.*\".*/ or line.match /','/
#    rescue Exception => e
#      puts e.message + ", ignored."
#    end
#  end
#end
#

class Format
  attr_reader :extensions

  def initialize dir, extensions
    @dir = dir
    @extensions = extensions
    @dir.freeze
    @extensions.freeze
    @handlers = extensions.collect{ |e| DirHandler.new dir, e }
  end

  def for_commas
    @handlers.each do |h|
      h.on_each_line do |line| 
        begin
          line.gsub! /,(\S)/, ', \1' unless line.match /.*\".*,.*\".*/ or line.match /','/
        rescue Exception => e
          puts e.message + ", ignored."
        end
      end
    end
  end 
end    

format = Format.new ARGV[0], [ "cpp", "h", "hpp", "md" ]
format.for_commas

