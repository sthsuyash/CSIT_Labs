import multiprocessing
from collections import defaultdict


class MapReduce:
    def __init__(self, num_workers=2):
        self.num_workers = num_workers

    def map(self, chunk):
        """Mapper: Processes input and produces (word, 1) key-value pairs."""
        word_counts = defaultdict(int)
        for word in chunk.split():
            word_counts[word] += 1
        return list(word_counts.items())

    def shuffle_sort(self, mapped_data):
        """Shuffling: Groups values by keys."""
        shuffled_data = defaultdict(list)
        for sublist in mapped_data:
            for word, count in sublist:
                shuffled_data[word].append(count)
        return shuffled_data

    def reduce(self, shuffled_data):
        """Reducer: Aggregates word counts."""
        return {word: sum(counts) for word, counts in shuffled_data.items()}

    def execute(self, text):
        """Executes the full MapReduce pipeline."""
        chunks = text.split("\n")  # Simulating distributed processing

        # Step 1: Map Phase (Parallel Processing)
        with multiprocessing.Pool(self.num_workers) as pool:
            mapped_data = pool.map(self.map, chunks)

        # Step 2: Shuffle and Sort Phase
        shuffled_data = self.shuffle_sort(mapped_data)

        # Step 3: Reduce Phase
        final_result = self.reduce(shuffled_data)

        return final_result


if __name__ == "__main__":
    text_corpus = """Deer Bear River
                     Car Car River
                     Deer Car Bear"""

    mr = MapReduce(num_workers=1)
    result = mr.execute(text_corpus)
    print("Final Word Count:", result)
