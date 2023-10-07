from pytube import YouTube

link="https://youtu.be/2lAe1cqCOXo"      #YouTube video link to download
yt=YouTube(link, use_oauth=True, allow_oauth_cache=True)
print("Title",yt.title) 
yd=yt.streams.get_highest_resolution()
yd.download(r'C:\\Users\\Lenovo\\Desktop\\New folder')      #path of the folder where video has to be downloaded
print("Video Downloaded")