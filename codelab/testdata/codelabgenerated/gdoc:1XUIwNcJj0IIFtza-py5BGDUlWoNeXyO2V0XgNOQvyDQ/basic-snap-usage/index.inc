<google-codelab
  id="codelabobj"
  title="Basic snap usage"
  feedback-link="https://github.com/ubuntudesign/tutorials.ubuntu.com/issues">
  <app-route
    route="{{route}}"
    tail="{{routeTail}}"></app-route>
  
  <google-codelab-step label="Introduction" duration="1">
    <p>Welcome to the world of snaps! In this tutorial, we are going to cover the very basics on how to use <a href="http://snapcraft.io/" target="_blank">snaps</a> on your Linux distribution, and you&#39;ll directly see the main benefits of them in action.</p>
<h2 class="checklist">What you&#39;ll learn</h2>
<ul class="checklist">
<li>How to install the <code>snapd</code> service on your system.</li>
<li>How to search for software.</li>
<li>How to check the list of installed pieces of software.</li>
<li>How snaps are updated.</li>
<li>What snap channels are and how to use them.</li>
<li>How to roll back to the previous version of a snap.</li>
</ul>
<p>If this looks like a long list to you, you will find that you are going to get through it in a breeze. All of the above is very easy to do thanks to the simplicity of the snap command line interface.</p>
<h2>What you&#39;ll need</h2>
<ul>
<li>Any supported GNU/Linux distribution (see next step of the tutorial for more details).</li>
<li>Some very basic knowledge of command line use.</li>
</ul>
<p>This tutorial is focused on using the <code>snap</code> command. Some command line tools are provided for you to simply copy and paste.</p>
<google-codelab-survey survey-id="basic-snap-usage-1">
<h4>How will you use this tutorial?</h4>
<paper-radio-group>
<paper-radio-button>Only read through it</paper-radio-button>
<paper-radio-button>Read it and complete the exercises</paper-radio-button>
</paper-radio-group>
<h4>What is your current level of experience working with snap?</h4>
<paper-radio-group>
<paper-radio-button>Novice</paper-radio-button>
<paper-radio-button>Intermediate</paper-radio-button>
<paper-radio-button>Proficient</paper-radio-button>
</paper-radio-group>
</google-codelab-survey>


  </google-codelab-step>
  
  <google-codelab-step label="Getting set up" duration="2">
    <h2>Installing snapd</h2>
<p><code>snapd</code> is the service which runs on your machine and keeps track of your installed snaps, interacts with the store and provides the <code>snap</code> command for you to interact with it. Installing it on any of the Linux distributions mentioned below is straight-forward.</p>
<h2>Different distributions:</h2>
<h3><strong>Arch</strong></h3>
<pre>$ sudo pacman -S snapd

# enable the snapd systemd service:
sudo systemctl enable --now snapd.socket</pre>
<h3><strong>Debian (Sid only)</strong></h3>
<pre>$ sudo apt install snapd</pre>
<h3><strong>Fedora</strong></h3>
<pre>$ sudo dnf copr enable zyga/snapcore
$ sudo dnf install snapd

# enable the snapd systemd service:
$ sudo systemctl enable --now snapd.service

# SELinux support is in beta, so currently:
$ sudo setenforce 0

# to persist, edit /etc/selinux/config to set SELINUX=permissive and reboot.</pre>
<h3><strong>Gentoo</strong></h3>
<p>Install the <a href="https://github.com/zyga/gentoo-snappy" target="_blank">gentoo-snappy overlay</a>.</p>
<h3><strong>OpenEmbedded/Yocto</strong></h3>
<p>Install the <a href="https://github.com/morphis/meta-snappy/blob/master/README.md" target="_blank">snap meta layer</a>.</p>
<h3><strong>openSuSE</strong></h3>
<pre>$ sudo zypper addrepo http://download.opensuse.org/repositories/system:/snappy/openSUSE_Leap_42.2/ snappy
$ sudo zypper install snapd</pre>
<h3><strong>OpenWrt</strong></h3>
<p>Enable the <a href="https://github.com/teknoraver/snap-openwrt/blob/master/README.md" target="_blank">snap-openwrt feed</a>.</p>
<h3><strong>Ubuntu</strong></h3>
<p>You should already be all set on ubuntu 16.04 LTS desktop. On 14.04, you need to install it though via:</p>
<pre>$ sudo apt install snapd</pre>
<p>Now that your system is all ready to go, let&#39;s install your first snap on it!</p>
<aside class="warning"><p>Important: we are currently disabling SELinux for some distributions and as such don&#39;t provide full confinement and security on those platforms yet. We are working heavily on this so that all Linux distributions benefit from these features as soon as possible.</p>
</aside>


  </google-codelab-step>
  
  <google-codelab-step label="Installing and running your first snap" duration="3">
    <h2><strong>Searching for a snap</strong></h2>
<p><code>snapd</code> is up and running now, so let&#39;s start using it! Here is how you can find any &#34;hello world&#34; kind of snaps in the store:</p>
<pre>$ snap find hello
hello-node-snap       1.0.2        bhdouglass      -          A simple hello world command
hello-mdeslaur        2.10         mdeslaur        -          GNU Hello, the &#34;hello world&#34; snap
hello-snap            0.01         muhammad        -          GNU hello-snap, the &#34;Hello, Snap!&#34; snap
hello                 2.10         canonical       -          GNU Hello, the &#34;hello world&#34; snap
hello-world           6.3          canonical       -          The &#39;hello-world&#39; of snaps
hello-sergiusens      1.0          sergiusens      -          hello world example
hello-gabriell        0.1          gabriell        -          Qt Hello World example
hello-bluet           0.1          bluet           -          Qt Hello World example
so-hello-world        0.2          shadowen        -          the old classic
hello-huge            1.0          noise           -          a really big snap</pre>
<p><code>snap find &lt;search terms&gt;</code> will query the store and list the results with their version number, developer names and description.</p>
<h2><strong>Install and execution</strong></h2>
<p>As you can see, a number of developers uploaded snaps related to &#34;hello world&#34;. Let&#39;s just install one of them.</p>
<pre>$ sudo snap install hello

hello (stable) 2.10 from &#39;canonical&#39; installed</pre>
<aside class="special"><p>Note: when you install the first snap, <code>snapd</code> will download the base OS snap (which includes the very minimal bits required apps in confinement and amounts to some megabytes). Consequently, your first snap download time can take a little bit longer than it will be in the future for any other snap.</p>
</aside>
<p>To run the command, simply type hello in the command line (which is a command provided by the <code>hello</code> snap:</p>
<pre>$ hello
Hello, world!</pre>
<p>This is obviously just a simple example, what it has in common with all other snaps though, is that it runs fully confined and can only access its own data.</p>
<h2><strong>Check which snaps are installed</strong></h2>
<p>See the snaps installed on your system with <code>snap list</code>, which will also tell you the software version, the unique revision, the developer of the installed snap, and any optional extra information.</p>
<pre>$ snap list
Name                     Version        Rev  Developer   Notes
hello                    2.10           20   canonical   -
core              16.04.1        423  canonical   -</pre>
<p>You will note that the <code>core</code> snap, containing the base snap system is also part of the list. Among other things, it includes a newer snapd, which will make sure you will always be up to date).</p>
<h2><strong>Keeping your system up to date</strong></h2>
<p>The good news is that snaps are updated automatically in the background every day! If you want, you can still get the latest version of all your snaps manually by running <code>snap refresh</code>. It will bring you completely up to date for all snaps, unless you specify a particular snap to refresh.</p>
<pre>$ sudo snap refresh hello
error: cannot refresh &#34;hello&#34;: snap &#34;hello&#34; has no updates available
$ sudo snap refresh
core updated
hello 64.75 MB [=====================================&gt;___]   12s
</pre>
<p>But these aren&#39;t the only features of the <code>snap</code> command: you can get way more fine-grained in terms of tracking various versions of the same app, depending on how close to current development you want to be. This is all possible thanks to the channel feature! We might delve into this later on.</p>


  </google-codelab-step>
  
  <google-codelab-step label="More snap features" duration="1">
    <h2><strong>Snap can ship one or more commands</strong></h2>
<p>Our first example was simple and shipped only one command, but in general snap packages can contain more than one command (for example a set of tools shipped in one snap). All commands are then namespaced by the snap package name. Run the steps below to see an example in action:</p>
<pre>$ sudo snap install hello-world
0 B / 20.00 KB [_______________________________________________________] 0.00 %

hello-world (stable) 6.3 from &#39;canonical&#39; installed
$ hello-world
Hello World!
$ hello-world.env
&lt; env variables &gt;</pre>
<aside class="special"><p>Note: for our first command, there is no command name suffix. This is due to the fact that the snap can have a default command.</p>
</aside>
<h2><strong>Snap can also host services</strong></h2>
<p>What is a service? A service is simply a long running command, which will ideally always be on or for a definite period of time to answer some requests.</p>
<p>Snaps can also ship system-wide services. If you install the snap package called <strong>shout</strong> (a self-contained web irc client), you can see this live in action - simply point your browser to <a href="http://localhost:9000/" target="_blank">http://localhost:9000/</a> to interact with the service.</p>
<p>Services of snaps are simply started/stopped on system startup and shutdown. They can be configured to be activated on demand as well.</p>
<h2><strong>Removing a snap</strong></h2>
<p>Removing a snap is just a command away, all you need to do is run <code>snap remove &lt;snap name&gt;</code>. In our case just do:</p>
<pre>$ sudo snap remove hello-world

hello-world removed</pre>
<p>Nice and clean, nothing is left-over! Application code, its run time dependencies and associated user data are all cleaned up. If your snap declared a service, they will as well be shut down and removed.</p>


  </google-codelab-step>
  
  <google-codelab-step label="Using versions and channels" duration="2">
    <p>Developers can release stable, candidate, beta and edge versions of a snap at the same time, to engage with a community who are willing to test upcoming changes. You decide how close to the leading edge you want to be.</p>
<p>By default, snaps are installed from the <strong>stable</strong> channel. By convention, developers use the <strong>candidate</strong> channel to provide a heads-up of a new stable revision, putting it in candidate a few days before stable so that people can test it out. The <strong>beta</strong> channel is for unfinished but interesting milestones, and the <strong>edge</strong> channel is conventionally used for regular or daily development builds that have passed some lightweight smoke-testing.</p>
<h2>Switching channel for installed apps</h2>
<pre>$ sudo snap refresh hello --channel=beta

hello (beta) 2.10.1 from &#39;canonical&#39; refreshed</pre>
<p>Now, you can run the beta version of the snap and see its output is different:</p>
<pre>$ hello
Hello, snap padawan!</pre>
<p><code>snapd</code> will now track the <strong>beta</strong> channel of the <strong>hello</strong> snap and get any updates delivered through it.</p>
<aside class="special"><p>Note that we could also have installed this snap directly from the beta channel via</p>
<p><code>$ sudo snap install hello --beta</code></p>
</aside>
<h2><strong>And revert if something goes wrong!</strong></h2>
<p>One of the features of <code>snapd</code> is to be able to simply roll back to a previous version of an application (including the data associated with the snap) for any reason:</p>
<pre>$ sudo snap revert hello

hello reverted to 2.10
$ hello
Hello, world!</pre>
<p>With this rollback system built-in, you can confidently update knowing that you will always have a way to go back to the previous working state!</p>


  </google-codelab-step>
  
  <google-codelab-step label="That&#39;s all folks!" duration="1">
    <h2><strong>Easy, wasn&#39;t it?</strong></h2>
<p>Congratulations! You made it!</p>
<p>By now you should have found snaps in the store, installed and updated them, changed between channels and much more. The <strong>snap</strong> command line is designed to be as simple and memorisable as possible. After using it just a couple of times, it should become second nature to you.</p>
<h2><strong>Next steps</strong></h2>
<ul>
<li>Jump into more advanced features and techniques of snaps, by reading the exhaustive &#34;<a href="https://tutorials.ubuntu.com/tutorial/advanced-snap-usage" target="_blank">Advanced snap usage</a>&#34; tutorial.</li>
<li>Be amazed by the ease of creating a snap for your project by following the snapcraft tutorial called &#34;<a href="https://tutorials.ubuntu.com/tutorial/create-first-snap" target="_blank">Creating your first snap</a>&#34;.</li>
<li>Join the snapcraft.io community by subscribing to <a href="https://lists.snapcraft.io/mailman/listinfo/snapcraft" target="_blank">our mailing list</a>.</li>
</ul>
<h2><strong>Further readings</strong></h2>
<ul>
<li><a href="http://snapcraft.io/docs/" target="_blank">Snapcraft.io documentation</a> is a good place to start reading the whole snap and snapcraft doc.</li>
<li>Check how you can <a href="http://snapcraft.io/community/" target="_blank">contact us and the broader community</a>.</li>
</ul>


  </google-codelab-step>
  
</google-codelab>