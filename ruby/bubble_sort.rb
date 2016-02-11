def swap(list, i)
  to_swap   = list[i-1]
  list[i-1] = list[i]
  list[i]   = to_swap
  list
end

def bubble_sort(list)
  n = list.size
  swapped = true
  loop do
    swapped = false
    1.upto(n-1) do |i|
      if list[i-1] < list[i]
        swap(list, i)
        swapped = true
      end
    end
    break unless swapped
  end
  list
end

def bubble_sort_optimized(list)
  n = list.size
  swapped = true
  loop do
    break unless swapped
    swapped = false
    1.upto(n-1) do |i|
      if list[i-1] < list[i]
        swap(list, i)
        swapped = true
      end
    end
    n = n - 1
  end

  list
end
