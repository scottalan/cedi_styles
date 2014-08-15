<?php
/**
 * @file cedi-ribbon.tpl.php
 */
?>

<div class="ribbon-wrapper">
  <?php if ($settings['ribbon']): ?>
    <div class="ribbon-wrapper-<?php print $settings['color'] ?>"><div class="ribbon-<?php print $settings['color'] ?>"><?php print $settings['text'] ?></div></div>
  <?php endif; ?>
<!--  --><?php //if (is_object($content)): ?>
<!--    --><?php //print $content->content; ?>
<!--  --><?php //else: ?>
<!--    --><?php //print $content; ?>
<!--  --><?php //endif; ?>
</div>
