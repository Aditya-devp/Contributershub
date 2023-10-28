from pytube import YouTube


def download_youtube_video(link: str, directory: str):
  yt = YouTube(link, use_oauth=True, allow_oauth_cache=True)
  yd=yt.streams.get_highest_resolution()
  yd.download(directory)      

if __name__ == '__main__':
  link = input("Enter youtube video link: ")
  directory = input("Enter the directory where you want to save the video: ")
  download_youtube_video(link, directory)
  print(f"The video has been saved to {directory}")
