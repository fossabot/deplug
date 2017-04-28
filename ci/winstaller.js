require('electron-winstaller').createWindowsInstaller({
  appDirectory: 'out/Deplug-win32-x64',
  outputDirectory: 'out',
  authors: 'deplug',
  iconUrl: 'https://raw.githubusercontent.com/deplug/images/master/deplug.ico',
  setupIcon: 'images/deplug-drive.ico',
  loadingGif: 'images/deplug-install.gif',
  noMsi: true,
  exe: 'Deplug.exe'
})
