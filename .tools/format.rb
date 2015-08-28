require_relative 'dir_handler'

extensions = [ "cpp", "h", "hpp", "md" ]
extensions.freeze
dir = ARGV[0] 
dir.freeze

#init handlers for all types of files
handlers = extensions.collect{ |e| DirHandler.new dir, e }

#for comma:
#   1,2,3,4   =>  1, 2, 3, 4
handlers.each do |h|
  h.on_each_line do |line| 
    begin
      line.gsub! /,(\S)/, ', \1' unless line.match /.*\".*,.*\".*/ or line.match /','/
    rescue Exception => e
      puts e.message + ", ignored."
    end
  end
end
