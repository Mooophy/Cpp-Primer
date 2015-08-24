#
# @Yue Wang 
# Aug 2015
# To use:
#   $ ruby remove_blank_tails.rb dir extension
#

class RemoveBlankTails

  def initialize dir, extension
    @paths = Dir.glob "#{ dir }/**/*.#{ extension }"
  end

  def perform
    @paths.each do |path|
      r = File.readlines(path).reverse
      i = r.find_index "}\n"
      if i != 0 and !i.nil? 
        content = r.drop(i).reverse
        File.open(path, 'w+'){ |file| file.puts content }
        yield path,i if i != 0
      end
    end
  end

end


if ARGV.size != 2
  puts "wrong argumens"
  exit
end

rbt = RemoveBlankTails.new ARGV[0], ARGV[1]
rbt.perform do |path, count|
  puts "[#{ path  }] : deleted [#{ count }] lines "
end
