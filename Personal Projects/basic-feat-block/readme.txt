=== Basic Feat Block ===
Contributors:      Ethan Kroeger
Tags:              block
Tested up to:      6.1
Stable tag:        1.2.0
License:           GPL-2.0-or-later
License URI:       https://www.gnu.org/licenses/gpl-2.0.html

TTRPG Feat block scaffolded with Create Block tool.

== Description ==

This is a standard block used for the display of content in the format of TTRPG
feats. This includes the name of the feat (featTitle), an optional (showFlavorField)
field for flavor text for the feat (featFlavor), the description of the 
prerequisite or prerequisites of the feat (featPrerequisites), the description 
of the benefit or benefits of the feat (featBenefits), and a toggleable field
(showSpecialField) which concerns the special aspects of a feat description, 
often containing additional mechanical information realted to the function of 
the feat (featSpecials).

== Installation ==

1. Upload the plugin files to the `/wp-content/plugins/basic-feat-block` directory, or install the plugin through the WordPress plugins screen directly.
2. Activate the plugin through the 'Plugins' screen in WordPress

== Changelog ==

= 1.2.0 =
* Added a featFlavor field for italicized flavor text in addition to standard
feat content, and the showFlavorField field in order to make it optional
